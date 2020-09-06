## 题目

判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

1. 数字 1-9 在每一行只能出现一次。
2. 数字 1-9 在每一列只能出现一次。
3. 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

数独部分空格内已填入了数字，空白格用 '.' 表示。

示例 1:
```
输入:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
输出: true
```
## method 3

- 通过数组记录每一个元素存在的特征值来判断
- 4-12ms

```c++
//12 ms
//convert char to int
//and get the unique number which correspond with its position
bool isValidSudoku(vector<vector<char>>& board) {
    int rows[9][9];
    int columns[9][9];
    int boxes[9][9];
    for(int i=0;i<9;++i)
    {
        for(int j=0;j<9;++j)
        {
            rows[i][j]=0;
            columns[i][j]=0;
            boxes[i][j]=0;
        }
    }
    for(int i=0;i<9;++i)
    {
        for(int j=0;j<9;++j)
        {
            if(board[i][j]=='.')continue;
            int num=board[i][j]-'1';
            if(rows[i][num]>0)return false;
            rows[i][num]=1;
            if(columns[j][num]>0)return false;
            columns[j][num]=1;
            int index=(i/3)*3+(j/3);
            if(boxes[index][num]>0)return false;
            boxes[index][num]=1;
        }
    }
    return true;
}

//4ms
bool isValidSudoku(vector<vector<char>>& board) {
    int row[9][9] = { 0 };
int columns[9][9] = { 0 };
int matrix[9][9] = { 0 };

for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
        
        if (board[i][j] != '.') {

            int num = board[i][j] - '0' - 1;
            row[i][num]++;
            columns[j][num]++;
            matrix[(i / 3) * 3 + j / 3][num]++;
            if (row[i][num] == 2 || columns[j][num] == 2 || matrix[(i / 3) * 3 + j / 3][num]==2)
                return false;
        }
    }
}
return true;
}

```


## method 2

- 通过set的insert是否能插入成功进行判断
- set-33ms, unordered_set-28ms

```c++
//unordered_set
bool isValidSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < 9; i++){
        unordered_set<char> line;
        unordered_set<char> row;
        unordered_set<char> cube;
        for(int j = 0; j < 9; j++){
            char e=board[i][j];
            if(e!='.'){
                pair<unordered_set<char>::iterator,bool> re;
                re=line.insert(e);
                if(! re.second){
                    return false;
                }
            }
        
            
            e=board[j][i];
            if(e!='.'){
                pair<unordered_set<char>::iterator,bool> re;
                re=row.insert(e);
                if(! re.second){
                    return false;
                }
            }
            int m = i/3*3+j/3;
            int n = i%3*3+j%3;
            e=board[m][n];
            if(e!='.'){
                pair<unordered_set<char>::iterator,bool> re;
                re=cube.insert(e);
                if(! re.second){
                    return false;
                }
            }
        }
    }
    return true;
}
    
//set
bool isValidSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < 9; i++){
        set<char> line;
        set<char> row;
        set<char> cube;
        for(int j = 0; j < 9; j++){
            char e=board[i][j];
            if(e!='.'){
                pair<set<char>::iterator,bool> re;
                re=line.insert(e);
                if(! re.second){
                    return false;
                }
            }
        
            
            e=board[j][i];
            if(e!='.'){
                pair<set<char>::iterator,bool> re;
                re=row.insert(e);
                if(! re.second){
                    return false;
                }
            }
            int m = i/3*3+j/3;
            int n = i%3*3+j%3;
            e=board[m][n];
            if(e!='.'){
                pair<set<char>::iterator,bool> re;
                re=cube.insert(e);
                if(! re.second){
                    return false;
                }
            }
        }
    }
    return true;
}
```

## method 1

- 通过find函数查找有没有重复的字符。
- 25ms

```c++
 bool isValidSudoku(vector<vector<char>>& board) {
    //row
    for(auto row:board){
        //col
        if(! checkRow(row)){
            return false;
        }
    }
    
    //col
    for(int i=0;i<9;i++){
        vector<char> col;
        for(int j=0;j<9;j++){
            col.push_back(board[j][i]);
        }
        if(! checkRow(col)){
            return false;
        }
    }
    
    //3x3
    for(int i=0;i<9;i++){
        vector<char> block;
        int sa=i/3;//shang-row
        int yu=i%3;//yu-col
        int start_row=sa*3;
        int start_col=yu*3;
        for(int m=0;m<3;m++){
            for(int n=0;n<3;n++){
                block.push_back(board[start_row+m][start_col+n]);
            }
        }
        if(! checkRow(block)){
            return false;
        }
    }
    return true;
    
    
}//end func

bool checkRow(vector<char> row){
    //col
    for(int i=0;i<row.size();i++){
        char e=row[i];
        if(e!='.' && i<8){
            vector<char>::iterator ite=find(row.begin()+i+1,row.end(),e);
            if(ite!=row.end())
                return false;
        }
    }
    return true;
}
```