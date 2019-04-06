#include <string>
#include <vector>

using namespace std;
bool visited[50];
int minCount = 101;

void dfs(string begin, string target, vector<string> words, int count) {
	if (begin == target) {
		if (count < minCount) minCount = count;
		return;
	}
	for (int i = 0; i < words.size(); i++) {
		string temp = words[i];
		int tempCount = 0;
		int l = temp.length();
		for (int j = 0; j < l; j++) {
			if (temp[j] != begin[j]) {
				tempCount++;
			}
		}
		if (tempCount <= 1 && !visited[i]) {
			visited[i] = true;
			dfs(temp, target, words, count + 1);
			visited[i] = false;
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	dfs(begin, target, words, 0);
	if (minCount > 100) minCount = 0;
	answer = minCount;
	return answer;
}