class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        
        minutesAngle = minutes * 6
        hourAngle = (hour%12) * 30

        angle1 = abs(hourAngle + 0.5*minutes - minutesAngle)
        angle2 = 360 - abs(hourAngle + 0.5*minutes - minutesAngle)
        return min(angle1, angle2)


