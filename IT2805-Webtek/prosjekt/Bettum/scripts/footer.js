let footerHTML = `
    <div id="telefon"><b>Tlf: </b><a href="tel:#">12345678</a></div>
    <div id="email"><b>E-post: </b><a href="mailto:#">example.com</a></div>
    <div id="adresse"><b>Adresse: </b>Bettumveien 84, 3178 Våle</div>
`;

let footer = document.querySelector("footer"); // henter footer elementet
footer.innerHTML = footerHTML; // legger inn HTML i footer elementet
