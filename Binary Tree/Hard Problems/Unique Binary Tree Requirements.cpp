https://practice.geeksforgeeks.org/problems/unique-binary-tree-requirements/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=unique-binary-tree-requirements

class Solution
{
public:
    bool isPossible(int a,int b)
    {
        //code here
        if(a==1 && b==2)return true;
        if(a==2&&b==3)return true;
        if(a==2&&b==1)return true;
        if(a==3&&b==2)return true;
        return false;
    }
};
