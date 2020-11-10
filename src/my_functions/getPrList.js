const { Octokit } = require("@octokit/core");

const octokit = new Octokit({ auth: process.env.TOKEN });

exports.handler = async () => {
    const prList = await octokit.request("GET /search/issues", {
        q: "is:open+is:pr+user:Gluckgames+archived:false+author:viroide"
    });
    const prResume = await Promise.all(prList.data.items.map(async pr => {
        const prInfo = await octokit.request("GET " + pr.pull_request.url, {});
        const prStatus = await octokit.request("GET " + prInfo.data.statuses_url, {});
        return {
            title: pr.title,
            comments: pr.comments,
            state: prStatus.data[0].state
        };
    }));
    return {
        statusCode: 200,
        body: JSON.stringify(prResume)
    };
};
