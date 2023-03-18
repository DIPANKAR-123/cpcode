// tidx=index of curr node
// range =start,end 
void build (vector<int>&segmentree,vector<int>&v,int tidx,int start,int end)
{
    if(start==end)
    {
        segmentree[tidx]=v[start];
        return;
    }
    int mid =start+(end-start)/2;
    build(segmentree,v,2*tidx,start,mid);
    build(segmentree,v,2*tidx+1,mid+1,end);
    // Self work // back track 
    segmentree[tidx]=segmentree[2*tidx]+segmentree[2*tidx+1];
}
void update(vector<int>&segmentree,int tidx,int start,int end,int update_idx,int value)
{
     if(start==end)
    {
        segmentree[tidx]=value;
        return;
    }
    int mid =start+(end-start)/2;
    if(update_idx<=mid)
    {
        update(segmentree,2*tidx,start,mid,update_idx,value);
    }
    else{
        update(segmentree,2*tidx+1,mid+1,end,update_idx,value);
    }
    // self work // relation
    segmentree[tidx]=segmentree[2*tidx]+segmentree[2*tidx+1];

}
int query (vector<int>&segmenttree,int tidx,int start,int end ,int l,int r)
{
    if(start>r || end<l)
    {  // disjoint
        return 0;
    }
    else if(start>=l&&end<=r)
    { 
        // total
        return segmenttree[tidx];
    }
    else{
        int mid=(start+end)/2;
        int leftans=query(segmenttree,2*tidx,start,mid,l,r);
        int rightans=query(segmenttree,2*tidx+1,mid+1,end,l,r);
        return leftans+rightans;
    }
}


  cin>>n;
 vector<int>a(n);
 for(int i=0;i<n;i++)
 {
     cin>>a[i];
 }
    int q;
    cin>>q;
    vector<int>segmenttree(4*n);
     build(segmenttree,a,1,0,n-1);
    for(int qt=0;qt<q;qt++)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int l,r;
            cin>>l>>r;
            // 0 based
            cout<<query(segmenttree,1,0,n-1,l,r);
        }
        else{
            int idx,value;
            cin>>idx>>value;
            update(segmenttree,1,0,n-1,idx,value);
        }
    }