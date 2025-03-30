#include<iostream>
#include<string>
using namespace std;
#include<bits/stdc++.h>
// Q1
int main()
{
    string act[]={"activity 1","activity 2","activity 3","activity 4","activity 5","activity 6"};
    int start[]={1,3,0,5,8,5};
    int finish[]={2,4,6,7,9,9};
    cout<<"the data entered by the user is : "<<endl<<endl;
    cout<<"activity name"<<"  "<<"start time"<<"  "<<" finish time"<<endl<<endl;
    for (int i=0;i<6;i++)
    {
        cout<<act[i]<<"         "<<start[i]<<"           "<<finish[i]<<endl;
    }
 int jobs_index[6];
    jobs_index[0]=0;
    int index=1;
    for (int i=1;i<6;i++)
    {
        int n=index-1;
        if(start[i]>=finish[jobs_index[n]])
        {
            jobs_index[index]=i;
            index++;
        }
    }
    cout<<endl;
    cout<<"the activities that could be performed are : "<<endl;
    for (int i=0;i<index;i++)
    {
        cout<<act[jobs_index[i]]<<" ";
    }

}

// Q2
int main()
{
    int arr[]= {900,940,950,1100,1500,1800};
    int dep[] = {910,1200,1120,1130,1900,2000};
    cout<<"the data entered by the user is : "<<endl<<endl;
    cout<<"arrival time"<<"  "<<"departure time"<<endl<<endl;
    for (int i=0;i<6;i++)
    {
        cout<<arr[i]<<"             "<<dep[i]<<endl;
    }
    int n=6;
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());

    int oky_train[6];
    oky_train[0]=0;
    int index=0;
    int platforms_needed=1,max_platforms=1;
    int i=1,j=0;
    while (i<n && j < n) 
    {
        if (arr[i]<=dep[j]) 
        { 
            platforms_needed++;
            i++;
        } 
        else 
        { 
            platforms_needed--;
            j++;
        }
        max_platforms = max(max_platforms, platforms_needed);
    }
    cout<<endl<<"the total number of platform required are : "<<max_platforms;
}


// Q3
int main()
{
    char job_ID[]={'a','b','c','d'};
    int deadline[]={4,1,1,1};
    int profit[]={20,10,40,30};
    cout<<"the entered data is : "<<endl<<endl;
    cout<<"job"<<"  "<<"deadline"<<"  "<<" profit"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<job_ID[i]<<"          "<<deadline[i]<<"        "<<profit[i]<<endl;
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(profit[j]<profit[j+1])
            {
                int temp1=profit[j];
                profit[j]=profit[j+1];
                profit[j+1]=temp1;

                int temp2=deadline[j];
                deadline[j]=deadline[j+1];
                deadline[j+1]=temp2;

                int temp3=job_ID[j];
                job_ID[j]=job_ID[j+1];
                job_ID[j+1]=temp3;
            }
        }
    }
    int soln=0;
    int day[]={-1,-1,-1,-1,-1};
    for(int i=0;i< 4;i++)
    {
        
        for(int j=deadline[i];j>0;j--)
        {
            if (day[j]==-1)  
            {
                day[j]=i; 
                soln+=profit[i];  
                break;  
            }
        }
    }
    cout<<"the total profit of the employee is : "<<soln;
}

// Q4
int main()
{
    int profit[]={60,100,120};
    int weight[]={10,20,30};
    float frac_weight[3];
    for(int i=0;i<3;i++)
    {
        frac_weight[i] = (float)profit[i] / weight[i];
    }
    int capacity=50;
    cout<<"the fractional weight ,profit,weght is :  "<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<"for item "<< i+1<<" "<<profit[i]<<"  " <<weight[i]<<" "<<frac_weight[i]<<endl;
    }
    cout<<endl<<"the total capacity of the bag is : "<<capacity<<endl;

    for (int i=0;i<3;i++)
    {
        for (int j=0;j<2;j++)
        {
            if(frac_weight[j]<frac_weight[j+1])
            {
                float temp=frac_weight[j];
                frac_weight[j]=frac_weight[j+1];
                frac_weight[j+1]=temp;

                int temp1=weight[j];
                weight[j]=weight[j+1];
                weight[j+1]=temp1;

                temp1=profit[j];
                profit[j]=profit[j+1];
                profit[j+1]=temp1;
            }
        }
    }
    float total_profit=0;
    int idx=0;
    while(capacity>0)
    {
        capacity=capacity-weight[idx];
        if(capacity>0)
        total_profit+=profit[idx];
        else{
            capacity=capacity+weight[idx];
            break;
        }
        idx++;
    }
    float f_profit = ((float)capacity/weight[idx])*profit[idx];
    total_profit+=f_profit;
    cout<<"the total profit is : "<<total_profit<<endl;

}


// Q5
class TreeNode {
    public:
        int val;
        char ch;
        TreeNode* left;
        TreeNode* right;
    
        TreeNode(int v, char c = '\0') {  // Default char for internal nodes
            val = v;
            ch = c;
            left = NULL;
            right = NULL;
        }
    };
    
    class Compare {
    public:
        bool operator()(TreeNode* a, TreeNode* b) {
            return a->val > b->val; // Min-heap based on frequency
        }
    };
    
    void encode(TreeNode* node, string path, unordered_map<char, string>& huffmanCodes) {
        if (!node) return;
    
        // If it's a leaf node, store the code
        if (!node->left && !node->right) {
            huffmanCodes[node->ch] = path;
            return;
        }
    
        encode(node->left, path + '0', huffmanCodes);
        encode(node->right, path + '1', huffmanCodes);
    }
    
    int main() {
        string chars = "abcdef";
        vector<int> freq = {5, 9, 12, 13, 16, 45};
    
        priority_queue<TreeNode*, vector<TreeNode*>, Compare> pq;
    
        // Create leaf nodes for each character
        for (int i = 0; i < freq.size(); i++) {
            pq.push(new TreeNode(freq[i], chars[i]));
        }
    
        // Build Huffman Tree
        while (pq.size() > 1) {
            TreeNode* left = pq.top(); pq.pop();
            TreeNode* right = pq.top(); pq.pop();
    
            TreeNode* parent = new TreeNode(left->val + right->val);
            parent->left = left;
            parent->right = right;
    
            pq.push(parent);
        }
    
        TreeNode* root = pq.top();
        unordered_map<char, string> huffmanCodes;
        encode(root, "", huffmanCodes);
    
        // Print Huffman Codes
        cout << "Huffman Codes:\n";
        for (auto& pair : huffmanCodes) {
            cout << pair.first << ": " << pair.second << "\n";
        }
    
        return 0;
    }
