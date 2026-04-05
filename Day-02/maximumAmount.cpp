class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n ,vector<int>(3 , INT_MIN) ));

        for(int k = 0 ;k<3; k++){

            if(coins[m-1][n-1]<0 && k>0){
                dp[m-1][n-1][k] = 0;
            }

            else {
                dp[m-1][n-1][k] = coins[m-1][n-1];
            }
        }


        for(int i = m-1; i>=0 ; i--){
            for(int j = n-1 ; j>=0 ; j--){
                if(i==m-1 && j==n-1){
                    continue;
                }

                for(int k = 0 ; k<3; k++){

                    int best = INT_MIN;


                    // move down
                    if(i+1 <m){
                        best = max(best , dp[i+1][j][k]);

                    }

                    // move up
                    if(j+1<n){
                        best = max(best , dp[i][j+1][k]);
                    }

                    // take current cell
                    int take = (best==INT_MIN) ? INT_MIN : coins[i][j];

                    // skip 

                    int skip = INT_MIN;

                    if(best!=INT_MIN){
                        take = coins[i][j] + best;
                    }
                    if(coins[i][j]<0 && k>0){
                        int bestSkip = INT_MIN;

                        if(i+1<m){
                            bestSkip = max(bestSkip , dp[i+1][j][k-1]);
                        }

                        if(j+1 < n){
                            bestSkip = max(bestSkip , dp[i][j+1][k-1]);
                        }

                        skip = bestSkip;
                    }

                    dp[i][j][k] = max(take , skip);
                }
            }
        }

        return dp[0][0][2];



    }
};