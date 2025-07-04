

````markdown
# 💼 FinacPlus 


## ✅ Special Cipher (Caesar Cipher + RLE)

```cpp
string specialCipher(string s, int shift) {
    string res = "";
    for (int i = 0; i < s.length();) {
        char c = (s[i] - 'A' + shift) % 26 + 'A';
        int cnt = 1;
        while (i + cnt < s.length() && s[i + cnt] == s[i]) cnt++;
        res += c + to_string(cnt);
        i += cnt;
    }
    return res;
}
````

🔹 Input: `"AABCCC", 3` → Output: `D2EF3`
🔹 Time: O(n), Space: O(1)

---

## ✅  Optimized Units (1 to 99)

```cpp
vector<int> coins = {1, 2, 5, 10, 20, 50};
int dp[100];
void computeMinUnits() {
    fill(dp, dp + 100, 1e9);
    dp[0] = 0;
    for (int c : coins)
        for (int i = c; i < 100; i++)
            dp[i] = min(dp[i], dp[i - c] + 1);
    double avg = 0;
    for (int i = 1; i < 100; i++) avg += dp[i];
    cout << "Avg units: " << avg / 99 << "\n";
}
```

🔹 Output: `Avg units: 3.4`
🔹 Time: O(n×m), Space: O(n)

---

## ✅  Product Metadata for Amazon

**Metadata for Shirt:**

* `title`, `brand`, `category`, `color`, `size[]`, `price`, `discount`, `rating`, `images[]`, `stock`, `material`, `slug`, `tags`

**Schema Overview:**

```sql
products(id, title, brand_id, category_id, price)
variants(id, product_id, size, color, stock)
images(id, product_id, url)
reviews(id, product_id, user_id, rating, comment)
```

**Use Cases:**

* Search & filter, inventory tracking, SEO (slugs), personalization, analytics

---

## ✅Real-Time Asset Portfolio (System Design)

![image](https://github.com/user-attachments/assets/c45f9ea0-62d9-4b48-8f03-a2dc1a0cdbb6)


### 🧠 Requirements

* 250 users, live portfolio of stocks/mutuals
* Refresh prices every 10 mins
* Real-time UI, price updates from NSE/AMFI

### ⚙️ Architecture

```plaintext
[Sources] → [PriceFetcher] → [Kafka] → [PortfolioService]
→ [PostgreSQL] + [Redis] → [API Gateway] → [Mobile/Web]
```

### 🧾 Schema

```sql
users(id), accounts(id, user_id), assets(id, symbol, type)
holdings(id, account_id, asset_id, qty), prices(asset_id, price, ts)
```

### 🔄 Refresh Flow

1. Fetch prices (cron)
2. Publish to Kafka
3. Recalculate portfolios
4. Update Redis + DB

### 🚀 Tech Stack

* **DB**: PostgreSQL, **Cache**: Redis, **Queue**: Kafka
* **Backend**: Node.js/NestJS, **Auth**: JWT
* **Frontend**: React/Flutter

---

## 🔐 Highlights

* Real-time performance with Redis
* Horizontal scaling for services
* Secure JWT + RBAC access
* Future-ready: WebSocket, Crypto assets

---

## 📌 Summary

| Problem       | Skills Demonstrated                   |
| ------------- | ------------------------------------- |
| Cipher + RLE  | String processing, encoding           |
| Coin DP       | Optimization, DP                      |
| Metadata      | Relational modeling, product search   |
| Portfolio HLD | System design, real-time architecture |

---


