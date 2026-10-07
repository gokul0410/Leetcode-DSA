/**
 * @param {number[][]} accounts
 * @return {number}
 */
var maximumWealth = function(accounts) {
    let row = accounts.length;
    let i=0 , col = accounts[0].length;
    let maxi_wealth = 0;
    for(;i<row;i++){
        let sum = 0 ;
        for(let j = 0;j<col;j++){
            sum+=accounts[i][j];
        }
        maxi_wealth = Math.max(maxi_wealth, sum);
    }
    return maxi_wealth;
};