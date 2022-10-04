class UndergroundSystem:

    def __init__(self):
        self.complete = {}
        self.chkin = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.chkin[id] = (stationName, t)
        
    def checkOut(self, id: int, stationName: str, t: int) -> None:
        if id in self.chkin:
            inat = self.chkin[id]
            complete_key = (inat[0],stationName)
            if complete_key in self.complete:
                cur_val = self.complete[complete_key]
                new_val = (cur_val[0]+t-inat[1], cur_val[1]+1)
            else:
                new_val = (t-inat[1],1)
            self.complete[complete_key] = new_val
    
    def getAverageTime(self, startStation: str, endStation: str) -> float:
        key = (startStation, endStation)
        cur_val = self.complete[key]
        return cur_val[0]/cur_val[1]


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)