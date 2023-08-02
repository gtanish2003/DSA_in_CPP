#include <iostream>
#include <stack>
#include <vector>
#include<climits>
using namespace std;

vector<int> nextSmallerElement(vector<int> &heights, int n)
{

    stack<int> s;
    s.push(-1);
    vector<int> ans(4);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = heights[i];
        while (s.top() != -1 && heights[s.top()] >= curr)
        {
            s.pop();
        }

        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector<int> PreviousSmallerElement(vector<int> &heights, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(4);
    for (int i = 0; i < n; i++)
    {
        int curr = heights[i];
        while (s.top() != -1 && heights[s.top()] >= curr)
        {
            s.pop();
        }

        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = PreviousSmallerElement(heights, n);

    int area = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        

        if (next[i] == -1)
        {
            next[i] = n;
        }
        
        int b = next[i] - prev[i] - 1;

        int newArea = l * b;
        area = max(area, newArea);
    }

    return area;
}



//MAIN LOGIC FOR THIS QUESTION

int maxArea(vector<vector<int>>&M,int n,int m){
    //comput area for first row
    int area=largestRectangleArea(M[0]);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            //row update by adding previous values
           if(M[i][j]!=0){
             M[i][j]=M[i][j]+M[i-1][j];
             }
             else{
                M[i][j]=0;
             }
    }

    //entire row is updated
     area=max(area,largestRectangleArea(M[i]));
     

     
    }

    return area;
}


int main(){
    vector<int>h={2,1,3,5,6};
    cout<<largestRectangleArea(h)<<endl;
}