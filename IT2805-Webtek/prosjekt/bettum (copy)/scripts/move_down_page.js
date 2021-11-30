
    // funksjon som flytter forsiden ned til under forside-bilde
function moveDownPage() {

    let foo = document.getElementById("main_index")
    foo.scrollIntoView({behavior: "smooth", block: "start", inline: "nearest"})
}

// gjøre slik at trykk funksjon på forside ikke fungerer på tablet og mobil

 if(window.innerWidth > 768) {
    document.getElementById("move_down_page_unit").setAttribute( "onClick", "moveDownPage()" )
}
    // en funksjon for å gjøre om på onclick ettersom skjermen justeres - in real time. 
function smallScreen (){
    if (window.innerWidth <= 768){
        document.getElementById("move_down_page_unit").setAttribute( "onClick", "" )
    }else if(window.innerWidth > 768) {
        document.getElementById("move_down_page_unit").setAttribute( "onClick", "moveDownPage()" )
    }
}
window.addEventListener('resize', smallScreen) 

