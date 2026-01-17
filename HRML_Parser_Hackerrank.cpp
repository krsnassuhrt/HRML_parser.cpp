#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
#include<unordered_map>
using namespace std;


string buildpath(stack <string> st)  //make path for tags like tag1.tag2.tag3
{
    stack<string> path;
    string pth="";
    while(!st.empty())  //in stack tag1,tag2,tag3
    {
        path.push(st.top());   //add in path stack it will be tag3,tag2,tag1
        st.pop();
    }
    while(!path.empty())
    {
        if(!pth.empty()){pth+=".";}   //add . b/w two tagname
        pth=pth+path.top();      //add in pth string it will be tag1.tag2.tag3
        path.pop();
    }
    
    return pth;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,q,i;
    cin>>n;    //input of number of lines of hrml 
    cin>>q;    //number of queries
    string s;
    vector<string>lines;   //vector of hrml language tag,attribute and its value
    cin.ignore();    //to ignore new line ..preventing new blank line getting added
    for(i=0;i<n;i++)
    {getline(cin,s);  // storing string in s and then the whole one line in vector
    lines.push_back(s);}
    stack <string> tagname;   //stack of tagname line by line
    unordered_map<string,string> mp;  //unordered map of tag path with attribute and its value
    for(auto l = lines.begin();l!=lines.end();l++)  //iterating vector for adding tagname in stack and removing when closing tag appears, finding attribute and its value and adding it
    {
        string line = *l;
        
        if(line[0] == '<' && line[1]!= '/')   //iterating only if it's not a closing tag
        {
            int i = 1;
            string tag= "";
            string att = "";
            string attv = "";
            while(i<line.size() && line[i]!=' ' && line[i]!='>')  //storing tagname in string and adding it into stack
            {
                tag+=line[i];
                i++;
            }
            
            tagname.push(tag);
            while(i < line.size() && line[i] == ' ')   //ignoring space after tagname
            {i++;}
            if(line[i]=='>'){}   //ignoring the loop if there is no attribute
            else
            {
                while(i < line.size() && line[i] == ' ')  //ignoring space after a attribute for second attribute
                {i++;}

                while(i < line.size() && line[i] != '>')
                {
                    while(i < line.size() && line[i] == ' ')
                    {i++;}

                    while(i<line.size() && line[i]!=' ')    //storing attribute name
                    {
                        att+=line[i];
                        i++;
                    }
                    while(i < line.size() && line[i] != '"')  //space after attribute name ignored
                    {i++;}
                    i++;     // first " ignored
                    while(i<line.size() && line[i]!='"')
                    {
                     attv+=line[i];    //storing attribute value
                     i++;
                    }
                    i++;
                    string key = buildpath(tagname) + "~" + att;
                    
                    mp[key] = attv;    //storing tag1.tag2.tag3~att,attribute_value in map
                    att="";attv="";    //reinitializing it to blank
                }
            }
        }
        
        else if(line[0] == '<' && line[1] == '/')  //poping ot tag namr after closing tag
        {
            tagname.pop();
        }
        
        
    }
    while(q--)   //answering the queries
    {
        string query;
        cin >> query;
        if(mp.count(query))
            cout << mp[query] << endl;
        else
            cout << "Not Found!" << endl;
    }
}
