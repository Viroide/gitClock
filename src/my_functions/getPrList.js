const { Octokit } = require("@octokit/core");

const octokit = new Octokit({ auth: process.env.TOKEN });

exports.handler = async () => {
    const response = await octokit.request("GET /search/issues", {
        q: "is:open+is:pr+user:Gluckgames+archived:false+author:viroide"
    });
    const prList = await Promise.all(response.data.items.map(async pr => {
        const r2 = await octokit.request("GET " + pr.pull_request.url, {});
        const r3 = await octokit.request("GET " + r2.data.statuses_url, {});
        return {
            title: pr.title,
            comments: pr.comments,
            state: r3.data[0].state
        };
    }));
    return {
        statusCode: 200,
        body: JSON.stringify(prList)
    };
};
