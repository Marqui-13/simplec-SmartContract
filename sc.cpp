#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>

using namespace eosio;
using namespace std;

CONTRACT example : public contract {
    public:
        using contract::contract;
        example(name receiver, name code, datastream<const char*> ds)
            : contract(receiver, code, ds) {}

        ACTION addfunds(name user, asset quantity) {
            require_auth(user);
            accounts acnts(get_self(), get_first_receiver().value);
            auto it = acnts.find(user.value);
            if (it == acnts.end()) {
                acnts.emplace(user, [&](auto& a) {
                    a.user = user;
                    a.balance = quantity;
                });
            } else {
                acnts.modify(it, user, [&](auto& a) {
                    a.balance += quantity;
                });
            }
        }

    private:
        TABLE account {
            name user;
            asset balance;
            uint64_t primary_key() const { return user.value; }
        };
        typedef eosio::multi_index<"accounts"_n, account> accounts;
};
