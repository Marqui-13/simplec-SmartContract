# EOSIO Example Smart Contract

This repository contains `sc.cpp`, a C++ smart contract designed for the EOSIO blockchain. It features a simple financial system where users can add funds to their accounts. Utilizing EOSIO's permission system, the contract ensures that only the account owner can add funds to their account.

## Prerequisites

- EOSIO Contract Development Toolkit (CDT)
- EOSIO node setup or access to a testnet/blockchain
- Basic understanding of EOSIO smart contract development and deployment

## Building the Contract

1. Clone this repository:

git clone https://github.com/Marqui-13/simplec-SmartContract.git

2. Navigate to the repository directory:

cd simplec-SmartContract

3. Compile the smart contract using the EOSIO.CDT:

eosio-cpp -o example.wasm sc.cpp --abigen

## Deployment

To deploy this contract to an EOSIO blockchain, use the `cleos` tool:

cleos set contract <account_name> /path/to/eosio-example-contract -p <account_name>@active

Replace `<account_name>` with the name of the account you're deploying the contract to.

## Usage

To add funds to an account, use the `addfunds` action. Ensure you have the necessary permissions to perform the action on behalf of the user account:

cleos push action <account_name> addfunds '["user_account", "10.0000 EOS"]' -p user_account@active

Replace `<account_name>` with your contract account name and `"user_account"` with the name of the user account to which funds are being added.

## Contributing

Contributions to improve the contract or its documentation are welcome. Please fork the repository, create your changes, and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- The EOSIO development community for their comprehensive documentation and examples.