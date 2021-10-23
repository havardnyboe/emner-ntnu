const todoList = document.querySelector("#todo-list");
const todoInput = document.querySelector("#todo-input");
const button = document.querySelector("#add");
const output = document.querySelector("#output");
let tasks = []; // lager en tom array

window.addEventListener("load", () => {
    // venter til siden er lastet
    button.addEventListener("click", addTask); // kjører addTask() når knappen trykkes
    todoInput.addEventListener("keyup", addOnEnter); // kjører addOnEnter() når enter trykkes
    todoList.addEventListener("click", toggleTask); // kjører toggleTask() når pekeren er over lista
    toggleTask(); // kjører toggleTask() for å starte med
});

function addTask() {
    const task = todoInput.value;
    if (!task) {
        // hvis task er tom
        alert(
            "Du kan ikke legge til en tom oppgave, venligst skriv inn et navn."
        );
    } else {
        const newTaskContainer = document.createElement("li");
        const newTask = document.createElement("input");
        const newTaskLabel = document.createElement("span");
        newTask.setAttribute("type", "checkbox"); // setter type til checkbox
        newTaskLabel.innerHTML = task; // legger inn task i span
        newTaskContainer.appendChild(newTask); // legger til checkbox i li
        newTaskContainer.appendChild(newTaskLabel); // legger til span i li
        todoList.appendChild(newTaskContainer); // legger til li i ul
        tasks.push([newTaskContainer, Date()]); // legger til task i tasks array
        console.log(tasks); // printer ut tasks array til konsoll
        todoInput.value = ""; // fjerner tekst i input
    }
    completedTasks(); // kjører completedTasks
}

function toggleTask() {
    document.querySelectorAll("input[type=checkbox]").forEach((checkbox) => {
        // går gjennom alle checkboxene
        checkbox.addEventListener("change", () => {
            // kjører når en checkbox endres
            if (checkbox.checked) {
                // hvis checkbox er checked
                checkbox.parentElement.classList.add("completed"); // tegner linje over tekst
            } else {
                checkbox.parentElement.classList.remove("completed"); // fjerner linje over tekst
            }
        });
    });
    completedTasks(); // kjører completedTasks
}

function addOnEnter(event) {
    if (event.keyCode === 13) {
        // hvis enter trykkes
        addTask();
    }
}

function completedTasks() {
    let completed = 0;
    tasks.forEach((element) => {
        // går gjennom alle tasks
        if (element[0].firstChild.checked) {
            // hvis checkbox er checked
            completed++; // legger til 1 i completed
        }
    });
    if (tasks.length === 0) {
        output.innerHTML = "Ingen gjøremål"; // hvis det ikke er noen tasks
    } else {
        output.innerHTML = `${completed} av ${tasks.length} oppgaver er fullført`; // skriver ut antall completed tasks
    }
}
