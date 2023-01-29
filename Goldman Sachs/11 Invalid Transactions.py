class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        city_times, inv = {}, []
        
        for i, v in enumerate(transactions):
            name, t, n, city = v.split(',')
            transactions[i] = name, t, n, city
            if name not in city_times:
                city_times[name] = {city: [t]}
            else:
                if city not in city_times[name]:
                    city_times[name][city] = [t]
                else:
                    city_times[name][city].append(t)
        
        for trans in transactions:
            name, t, n, city = trans
            t = int(t)
            if int(n) > 1000:
                inv.append(','.join(trans))
            else:
                dct = city_times[name]
                for c, times in dct.items():
                    if city == c:
                        continue
                    else:
                        if any(list(map(lambda x:abs(int(x) - t) <= 60, times))):
                            inv.append(','.join(trans))
                            break
        return inv
      
"""
    Time Complexity : O(n^2)
    Space Complexity : O(n)
"""
