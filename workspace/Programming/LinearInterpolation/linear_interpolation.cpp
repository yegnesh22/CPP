/*
Linear interpolation

Write a C++ function that performs linear interpolation for a given timestamp
(tquery), from a set of timestamps and acceleration measurements from an IMU.
Each value of the acceleration vectors has a corresponding value in the vector
of timestamps. The function should return the interpolated value at the query
time.

Feel free to share any of your thoughts, comments and assumptions.
*/

#include <algorithm>
#include <cmath>
#include <vector>

double interpolateAcceleration(const std::vector<double>& timestamps,
                               const std::vector<double>& accelerations,
                               const double tquery)
{
        auto u = upper_bound(timestamps.begin(), timestamps.end(), tquery);
        auto l = lower_bound(timestamps.begin(), timestamps.end(), tquery);

        // Correction if tquery has an exact match
        if (*l > tquery)
                l--;

        size_t loff = l - timestamps.begin();
        size_t uoff = u - timestamps.begin();

        double f = (tquery - *l) / (*u - *l);
        return std::lerp(accelerations[loff], accelerations[uoff], f);
}


