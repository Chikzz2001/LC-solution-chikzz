​
reverse(res.begin(),res.end());
return res;
}
};
​
​
/*
​
a a b c a c a
a b c a
a b c a
a b c a
​
vector<int> movesToStamp(const string& stamp, string target) {
vector<int> ans;
// Return early if |stamp| and |target| are the same size.
if (size(stamp) == size(target)) {
if (stamp == target) ans.push_back(0);
return ans;
}
​
bool matched = true;
while (matched) {
matched = false;
for (int pos = size(target) - size(stamp); pos >= 0; --pos) {
if (match(stamp, target, pos)) {
matched = true;
ans.push_back(pos);
// "stamp-out" |target| if we have a match.
for (int i = 0; i < size(stamp); ++i) {
target[pos + i] = '?';
}
}
}
}
// Did we stamp out everything?
if (target.find_first_not_of('?') != string::npos) return {};
​
// We need the answer in the reverse order.
reverse(begin(ans), end(ans));
return ans;
}
​
*/
```