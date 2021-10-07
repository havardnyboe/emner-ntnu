/* Part 2 */
console.log('PART 2')

for (let i = 1; i < 21; i++) { 
    console.log(i) 
}

/* Part 3 */
console.log('PART 3')

const numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]

for (let i = 0; i < numbers.length; i++) { 
    const element = numbers[i]; 
    let output = ""; 
    if (element % 3 === 0) { // sjekker om tallet er delbart med 3
        output += "eple" // legger til eple
    }
    if (element % 5 === 0) { // sjekker om tallet er delbart med 5
        output += "kake" // legger til kake
    }
    if (output === "") { // sjekker om output er tom
        output += element // legger til elementet i output
    }
    console.log(output) // skriver ut output
}
/* Part 4 */
document.querySelector('#title').innerHTML = 'Hello, JavaScript';

/* Part 5 */
window.addEventListener('load', () => {
    const buttons = document.querySelectorAll('.button'); // henter alle knappene
    const func = [changeDisplay, changeVisibility, reset]; // lager en array med funksjonene
    for (let i = 0; i < buttons.length; i++) { // går gjennom alle knappene
        buttons[i].addEventListener('click', func[i]) // legger til en funksjon til knappen
    }
});

changeDisplay = () =>  {
    document.querySelector('#magic').style.display = 'none';
}

changeVisibility = () => {
    document.querySelector('#magic').style.visibility = 'hidden';
    document.querySelector('#magic').style.display = 'block';
}

reset = () => {
    document.querySelector('#magic').style.visibility = 'visible';
    document.querySelector('#magic').style.display = 'block';
}

/* Part 6 */
const technologies = [
    'HTML5',
    'CSS3',
    'JavaScript',
    'Python',
    'Java',
    'AJAX',
    'JSON',
    'React',
    'Angular',
    'Bootstrap',
    'Node.js'
];

technologies.forEach(element => {
    document.querySelector('#tech').innerHTML += `<li>${element}</li>`
});
