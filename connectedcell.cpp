#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'connectedCell' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */
vector<vector<bool>> searched;
vector<vector<int>> mat;
int n;
int m;
int maxConnection=0;
int tempCount=1;

void createVariables(vector<vector<int>> matrix){
    mat = matrix;
    n = mat.size();
    m = mat[0].size();
    vector<bool> emty(m,true);
    vector<vector<bool>> arr(n,emty);
    searched = arr;    
}

void connectionSearch(int pI,int pJ){

    int sI=(pI==0)?pI:pI-1;
    int eI=(pI+1==n)?pI:pI+1;
    
    int sJ=(pJ==0)?pJ:pJ-1;
    int eJ=(pI+1==m)?pJ:pJ+1;
  
  //cout<<"si : "<<sI<<" ei : "<<eI<<endl;
 // cout<<"sj : "<<sJ<<" ej : "<<eJ<<endl;
    for (int i=sI; i<=eI; i++) {
    
    for (int j=sJ; j<=eJ; j++) {
    //    cout<<"i : "<<i<<" j : "<<j<<" d: "<<mat[i][j]<<endl;
      if(mat[i][j]==1 && searched[i][j]){
         // cout<<"working"<<endl;
          searched[i][j]=false;
          tempCount++;
          connectionSearch(i,j);
      }
 }
 }
    
}

int connectedCell(vector<vector<int>> matrix) {
createVariables(matrix);

for (int i=0; i<n; i++) {
    
  for (int j=0; j<m; j++) {
     // cout<<"i : "<<i<<" j : "<<j<<" search: "<<searched[i][j]<<endl;
      if(matrix[i][j]==1 && searched[i][j]){
          searched[i][j]=false;
          tempCount=1;
          connectionSearch(i,j);
          maxConnection = (tempCount>maxConnection)? tempCount:maxConnection;
      }
    //  cout<<"i : "<<i<<" j : "<<j<<" search: "<<searched[i][j]<<endl;
 }
 }
return maxConnection;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    vector<vector<int>> matrix(n);

    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < m; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
