class Solution
{
private:
  char rtn = '#';
  int * arr;
  queue<char > cqueue;
public:
  //Insert one char from stringstream
    Solution () {
      arr = new int[256];
      memset(arr, 0, sizeof(arr));
    }
    void Insert(char ch){
      ++arr[ch];
      if (arr[ch] == 1) {
        cqueue.push(ch);
        if (rtn == '#') {
          rtn = ch;
        }
      } else if (ch ==rtn && arr[ch] > 0){
        while (!cqueue.empty() && arr[cqueue.front()] > 1) {
          cqueue.pop();
        }
        if (cqueue.empty())
          rtn = '#';
        else 
          rtn = cqueue.front();
      }
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
      return rtn;
    }
    ~Solution () {
      delete[] arr;
    }

};