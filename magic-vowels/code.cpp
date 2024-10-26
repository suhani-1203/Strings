
string addDollarAfterTwoVowels(int N, const string& S) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    string result;
    result.reserve(N);  // Reserve space to avoid reallocations for large inputs

    int i = 0;
    while (i < N) {
        if (i < N - 1 && vowels.count(S[i]) && vowels.count(S[i + 1])) {
            // Check if there are more than two consecutive vowels
            int j = i + 2;
            while (j < N && vowels.count(S[j])) {
                j++;
            }

            if (j == i + 2) {
                // Exactly two consecutive vowels
                result += S[i];
                result += S[i + 1];
                result += '$';
                i += 2;  // Move past these two vowels
            } else {
                // More than two consecutive vowels, add the current segment without $
                while (i < j) {
                    result += S[i];
                    i++;
                }
            }
        } else {
            // Not consecutive vowels, just add the character
            result += S[i];
            i++;
        }
    }

    return result;
}

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    string modifiedString = addDollarAfterTwoVowels(N, S);
    cout << modifiedString << endl;

    return 0;
}
