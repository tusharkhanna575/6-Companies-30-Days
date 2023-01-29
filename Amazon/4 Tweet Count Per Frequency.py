import bisect

class TweetCounts:

    def __init__(self):
        self.tweets=dict()    

    def get_intervals(self,freq,start,end):
        freq_dict = {'minute': 60, 'hour': 3600, 'day': 86400}
        res, interval = [],freq_dict[freq]
        while start <= end:
            res.append([start,min(start+interval-1,end)])
            start = start+interval
        return res

    def recordTweet(self, tweetName: str, time: int) -> None:
        if tweetName in self.tweets:
            index= bisect.bisect_left(self.tweets[tweetName],time)
            if index ==0: 
                self.tweets[tweetName] = [time] + self.tweets[tweetName]
            elif index == len(self.tweets[tweetName]):
                self.tweets[tweetName] = self.tweets[tweetName] + [time]
            else: 
                self.tweets[tweetName] = self.tweets[tweetName][:index] + [time] + self.tweets[tweetName][index:]
        else: 
            self.tweets[tweetName] = [time]

    def getTweetCountsPerFrequency(self, freq: str, tweetName: str, startTime: int, endTime: int) -> List[int]:
        intervals = self.get_intervals(freq,startTime,endTime)
        res = []
        for start,end in intervals:
            left = bisect.bisect_left(self.tweets[tweetName], start)
            right = bisect.bisect_left(self.tweets[tweetName], end+1)
            res.append(right-left)
        return res

# Your TweetCounts object will be instantiated and called as such:
# obj = TweetCounts()
# obj.recordTweet(tweetName,time)
# param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime)


"""
    Time Complexity : O(nlogn)
    Space Complexity : O(n)
"""
