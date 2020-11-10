const { Octokit } = require("@octokit/core");

const octokit = new Octokit({ auth: process.env.TOKEN });

exports.handler = async () => {
    const q = "is:open+is:pr+user:Gluckgames+archived:false+author:viroide";
    const prList = await octokit.request("GET /search/issues", { q });
    const prResume = await Promise.all(prList.data.items.map(async pr => {
        const prInfo = await octokit.request("GET " + pr.pull_request.url, {});
        const prStatus = await octokit.request("GET " + prInfo.data.statuses_url, {});
        const state = prStatus.data.length > 0? prStatus.data[0].state : "unknown";
        return {
            id: pr.id,
            title: pr.title,
            comments: pr.comments,
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
