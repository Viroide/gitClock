const { Octokit } = require("octokit");

const octokit = new Octokit({ auth: process.env.TOKEN });

exports.handler = async () => {
  const q = "is:open+is:pr+user:Lingokids+archived:false+assignee:viroide";
  const prList = await octokit.request("GET /search/issues", { q });
  const prResume = await Promise.all(prList.data.items.map(async pr => {
    const prInfo = await octokit.request("GET " + pr.pull_request.url, {});

    let state = "";
    prInfo.data.draft ? "unknown" : "success"
    if (prInfo.data.draft) {
      state = "unknown";
    } else if (prInfo.data.mergeable) {
      state = "success";
    } else {
      state = "error";
    }
    return {
      id: pr.id,
      title: pr.title,
      comments: pr.comments - 1,
      state
    };
  }));

  return {
    statusCode: 200,
    headers: {
      'Allow': 'GET',
      'Content-Type': 'application/json',
    },
    body: JSON.stringify(prResume)
  };
};

