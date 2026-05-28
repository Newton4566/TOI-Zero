#include <iostream>
#include <string>
using namespace std;

// Parse a time string in format H.MM or HH.MM
// Returns {hours, minutes} or {-1, -1} if invalid
pair<int,int> parseTime(const string& s) {
    size_t dot = s.find('.');
    if (dot == string::npos) return {-1, -1};

    string hourStr = s.substr(0, dot);
    string minStr  = s.substr(dot + 1);

    // Minutes must be exactly 2 digits
    if (minStr.size() != 2) return {-1, -1};

    // Check all digits
    for (char c : hourStr) if (!isdigit(c)) return {-1, -1};
    for (char c : minStr)  if (!isdigit(c)) return {-1, -1};

    int h = stoi(hourStr);
    int m = stoi(minStr);

    // Valid range: hour 0–23, minute 0–59
    if (h < 0 || h > 23) return {-1, -1};
    if (m < 0 || m > 59) return {-1, -1};

    return {h, m};
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    auto [ih, im] = parseTime(s1);
    auto [oh, om] = parseTime(s2);

    // Check for invalid input
    if (ih == -1 || oh == -1) {
        cout << "ERROR" << endl;
        return 0;
    }

    int entryMin = ih * 60 + im;
    int exitMin  = oh * 60 + om;

    // Exit must be strictly after entry (same day, i < o)
    if (exitMin <= entryMin) {
        cout << "ERROR" << endl;
        return 0;
    }

    int diff = exitMin - entryMin;

    // Less than 15 minutes → FREE
    if (diff < 15) {
        cout << "FREE" << endl;
        return 0;
    }

    // Ceiling division: compute hours parked (partial hour counts as full)
    int hours = (diff + 59) / 60;

    // Pricing table
    int rates[] = {0, 25, 50, 80, 110, 145, 180, 250};
    int fee = (hours >= 7) ? 250 : rates[hours];

    cout << fee << endl;
    return 0;
}