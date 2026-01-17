#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
#include<unordered_map>
using namespace std;


string buildpath(stack <string> st)
{
    stack<string> path;
    string pth="";
    while(!st.empty())
    {
        path.push(st.top());
        st.pop();
    }
    while(!path.empty())
    {
        if(!pth.empty()){pth+=".";}
        pth=pth+path.top();
        path.pop();
    }
    
    return pth;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,q,i;
    cin>>n;
    cin>>q;
    string s;
    vector<string>lines;
    cin.ignore();
    for(i=0;i<n;i++)
    {getline(cin,s);
    lines.push_back(s);}
    stack <string> tagname;
    unordered_map<string,string> mp;
    for(auto l = lines.begin();l!=lines.end();l++)
    {
        string line = *l;
        
        if(line[0] == '<' && line[1]!= '/')
        {
            int i = 1;
            string tag= "";
            string att = "";
            string attv = "";
            while(i<line.size() && line[i]!=' ' && line[i]!='>')
            {
                tag+=line[i];
                i++;
            }
            
            tagname.push(tag);
            while(i < line.size() && line[i] == ' ')
            {i++;}
            if(line[i]=='>'){}
            else
            {
                while(i < line.size() && line[i] == ' ')
                {i++;}

                while(i < line.size() && line[i] != '>')
                {
                    while(i < line.size() && line[i] == ' ')
                    {i++;}

                    while(i<line.size() && line[i]!=' ')
                    {
                        att+=line[i];
                        i++;
                    }
                    while(i < line.size() && line[i] != '"')
                    {i++;}
                    i++;
                    while(i<line.size() && line[i]!='"')
                    {
                     attv+=line[i];
                     i++;
                    }
                    i++;
                    string key = buildpath(tagname) + "~" + att;
                    
                    mp[key] = attv;
                    att="";attv="";
                }
            }
        }
        
        else if(line[0] == '<' && line[1] == '/')
        {
            tagname.pop();
        }
        
        
    }
    while(q--)
    {
        string query;
        cin >> query;
        if(mp.count(query))
            cout << mp[query] << endl;
        else
            cout << "Not Found!" << endl;
    }
}
