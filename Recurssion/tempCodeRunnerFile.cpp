 vector<vector<int>> ans;

    ans = combination(candidates,target);

    for(int i=0;i<ans.size();i++)
    {
        cout<<"[";
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<"";
        }
        cout<<"]";

        cout<<" ";

        
    }