/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    var ans = "";
    var byte = 0;
    var counter = 1;  
    while (num != 0) {
        byte = Math.round(num % 10);
        if (byte === 4) {
            if (counter === 1) {
                ans = "IV" + ans;
            }
            else if (counter === 2) {
                ans = "XL" + ans;
            }
            else {
                ans = "CD" + ans;
            }
        }
        else if (byte === 9 ) {
            if (counter === 1) {
                ans = "IX" + ans;
            }
            else if (counter === 2) {
                ans = "XC" + ans;
            }
            else {
                ans = "CM" + ans;
            }
        }
        else {
            var fif = Math.floor(byte / 5);
            var mod = Math.round(byte % 5);
            if (counter === 1) {
                while(mod > 0) ans = "I" + ans, mod--;
                while (fif > 0) ans = "V" + ans, fif--;
            }
            else if (counter === 2) {
                while(mod > 0) ans = "X" + ans, mod--;
                while (fif > 0) ans = "L" + ans, fif--;
            }
            else if (counter === 3) {
                while(mod > 0) ans = "C" + ans, mod--;
                while (fif > 0) ans = "D" + ans, fif--;
            }
            else {
                while(mod > 0) {
                    ans = "M" + ans;
                    mod --;
                }
            }
        }
        num = Math.floor(num / 10);
        counter++;
    }
    return ans;
};