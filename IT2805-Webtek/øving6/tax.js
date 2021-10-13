inputTax = document.querySelector('#tax');
income = document.querySelector('#income');
wealth = document.querySelector('#wealth');
document.addEventListener("keyup", () => {
    let tax = (0.35 * income.value) + (0.25 * wealth.value);
    inputTax.value = tax;
});
