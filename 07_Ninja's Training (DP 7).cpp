int solve(int day, int last , vector<vector<int>>&points, vector<vector<int>>&dp)
{
    if(dp[day][last]!=-1) return dp[day][last];

    if(day==0){
        int mx=0;
        for(int i=0;i<=2;i++){
            if(i!=last){
                mx=max(mx,points[0][i]);
            }
        }
        return dp[day][last]=mx;
    }

    int mx=0;
    for(int i=0;i<=2;i++){
        if(i!=last){
            int take=points[day][i] + solve(day-1,i,points,dp);
            mx=max(mx,take);
        }
    }
    return dp[day][last]=mx;
}
// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     // Write your code here.
//     vector<vector<int>>dp(n,vector<int>(4,0));
//     // return solve(n-1,3,points,dp);
//     dp[0][0]=max(points[0][1],points[0][2]);
//     dp[0][1]=max(points[0][0],points[0][2]);
//     dp[0][2]=max(points[0][0],points[0][1]);
//     dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));

//     for(int day=1;day<n;day++){
//         for(int last=0;last<4;last++){
//             for(int task=0;task<=2;task++){
//                 if(last!=task){
//                     int take=points[day][task] + dp[day-1][task];
//                     dp[day][last]=max(dp[day][last],take);
//                 }
//             }
//         }
//     }
//     return dp[n-1][3];

// }


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int>prev(4,0);
    // return solve(n-1,3,points,dp);
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);
    prev[3]=max(points[0][0],max(points[0][1],points[0][2]));

    for(int day=1;day<n;day++){
        vector<int>cur(4,0);
        for(int last=0;last<4;last++){
            cur[last]=0;
            for(int task=0;task<=2;task++){
                if(last!=task){
                    cur[last]=max(cur[last],points[day][task] + prev[task]);
                   
                }
            }
        }
        prev=cur;
    }
    return prev[3];

}
