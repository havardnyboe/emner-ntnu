inputTax = document.querySelector("#tax");
income = document.querySelector("#income");
wealth = document.querySelector("#wealth");
document.addEventListener("keyup", () => {
    let tax = 0.35 * Number(income.value) + 0.25 * Number(wealth.value);
    inputTax.value = tax;
});
