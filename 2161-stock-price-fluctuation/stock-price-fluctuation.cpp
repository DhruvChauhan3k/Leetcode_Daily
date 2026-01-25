class StockPrice {
public:
    // Map: Timestamp -> Price (The Source of Truth)
    unordered_map<int, int> timestampPriceMap;
    
    // Max Heap for Maximum Price: stores {price, timestamp}
    priority_queue<pair<int, int>> maxPQ;
    
    // Min Heap for Minimum Price: stores {price, timestamp}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPQ;
    
    // Track the latest time seen so far for current()
    int latestTimestamp;

    StockPrice() {
        latestTimestamp = 0;
    }
    
    void update(int timestamp, int price) {
        // 1. Update the "Truth"
        timestampPriceMap[timestamp] = price;
        latestTimestamp = max(latestTimestamp, timestamp);
        
        // 2. Push to both heaps (we don't remove the old version yet)
        maxPQ.push({price, timestamp});
        minPQ.push({price, timestamp});
    }
    
    int current() {
        return timestampPriceMap[latestTimestamp];
    }
    
    int maximum() {
        // Keep popping while the top is "stale"
        while (true) {
            int price = maxPQ.top().first;
            int time = maxPQ.top().second;
            
            // Check if this heap entry matches the actual current price
            if (timestampPriceMap[time] == price) {
                return price;
            }
            // If not match, it's garbage. Throw it away.
            maxPQ.pop();
        }
    }
    
    int minimum() {
        // Keep popping while the top is "stale"
        while (true) {
            int price = minPQ.top().first;
            int time = minPQ.top().second;
            
            if (timestampPriceMap[time] == price) {
                return price;
            }
            minPQ.pop();
        }
    }
};