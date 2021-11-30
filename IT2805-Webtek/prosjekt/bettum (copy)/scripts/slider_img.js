window.onload = () => {
    document.querySelector("#arrow_left").addEventListener("click", () => { forrigeBilde(15000) }); // setter inn forrige bilde ved klikk på pil venstre og setter delay til 20 sekunder
    document.querySelector("#arrow_right").addEventListener("click", () => { nesteBilde(15000) }); // setter inn neste bilde ved klikk på pil høyre og setter delay til 20 sekunder
    document.onkeydown = keySlide; // setter inn bilder ved hjelp av piltast
};

let bildeDiv = document.getElementById("img_slider");
let bildeListe = [
    "img/gård_sommer.jpg",
    "img/gård_vinter.jpg",
    "img/gård_vinter_2.jpg",
    "img/gård_vinter_3.jpg",
    "img/honningpåbord.jpg",
    "img/oppstilthonning.jpg",
    "img/rennendehonning.jpg",
]; // liste med bilder
let bildenr = 0;
let slideShow = nesteBilde;
let intervall = setInterval(slideShow, 5000); // setter inn bilder automatisk

// funksjon for å sette inn neste bilde
function nesteBilde(delay = 5000) {
    if (bildenr >= bildeListe.length - 1) {
        bildenr = 0;
    } else {
        bildenr++;
    }
    clearInterval(intervall); // stopper automatisk innsetting av bilder
    console.log(bildenr);
    bildeDiv.innerHTML = `<img class="img_slide" src="${bildeListe[bildenr]}" alt="${bildeListe[bildenr]}">`; // setter inn bilde manuelt
    intervall = setInterval(slideShow, delay); // setter inn bilder automatisk
}

// funksjon for å sette inn forrige bilde
function forrigeBilde(delay = 5000) {
    if (bildenr <= 0) {
        bildenr = bildeListe.length - 1;
    } else {
        bildenr--;
    }
    clearInterval(intervall); // stopper automatisk innsetting av bilder
    console.log(bildenr);
    bildeDiv.innerHTML = `<img class="img_slide" src="${bildeListe[bildenr]}" alt="${bildeListe[bildenr]}">`; // setter inn bilde manuelt
    intervall = setInterval(slideShow, delay); // setter inn bilder automatisk
}

// funksjon for å sette inn bilder ved hjelp av piltast
function keySlide(keypress) {
    if (keypress.keyCode == "37") { // venstre pil
        forrigeBilde(15000);
    } else if (keypress.keyCode == "39") { // høyre pil
        nesteBilde(15000);
    }
}
