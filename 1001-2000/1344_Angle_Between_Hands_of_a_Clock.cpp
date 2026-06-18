/*
Problem Number: 1344
Problem Name: Angle Between Hands of a Clock

LeetCode Link:
https://leetcode.com/problems/angle-between-hands-of-a-clock/

Difficulty: Medium

Topics:
Math, Geometry

Approach:
1. Minute hand moves:
      360° / 60 = 6° per minute

2. Hour hand moves:
      360° / 12 = 30° per hour
      and also moves continuously:
      0.5° per minute

3. Calculate:
      minuteAngle = minutes × 6
      hourAngle = hour × 30 + minutes × 0.5

4. Find absolute difference.

5. Return the smaller angle:
      min(diff, 360 - diff)

Time Complexity:
O(1)

Space Complexity:
O(1)
*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Position of hour hand
        double hourAngle = (hour % 12) * 30 + minutes * 0.5;
        
        // Position of minute hand
        double minuteAngle = minutes * 6;
        
        // Absolute difference
        double diff = abs(hourAngle - minuteAngle);
        
        // Smaller angle
        return min(diff, 360.0 - diff);
    }
};
