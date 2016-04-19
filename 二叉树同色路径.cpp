ass LongestPath {
public:
    LongestPath(){memset(dp,0,sizeof dp);ans=0;}
    int findPath(TreeNode* root){
    	// write code here
    	dfs(root,1);
    	return ans;
    }
    void dfs(TreeNode *root,int id){
    	if(root==NULL) return;
    	dfs(root->left,id<<1);dfs(root->right,id<<1|1);
    	if(root->val==0){
    		dp[id][0]=max(dp[id<<1][0],dp[id<<1|1][0])+1;
    		ans=max(ans,dp[id<<1][0]+dp[id<<1|1][0]+1);
    	}
    	else{
    		dp[id][1]=max(dp[id<<1][1],dp[id<<1|1][1])+1;
    		ans=max(ans,dp[id<<1][1]+dp[id<<1|1][1]+1);
    	}
    }
private:
	int dp[1010][2];
	int ans;
};
