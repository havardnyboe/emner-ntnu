const todoList = document.querySelector("#todo-list");
const todoInput = document.querySelector("#todo-input");
const button = document.querySelector("#add");
window.addEventListener("load", () => {
    button.addEventListener("click", addTask);
});

function addTask() {
    // console.log("addTask");
    const task = todoInput.value;
    console.log(task);
    if (!task) {
        alert("Please enter a task");
    } else {
        const newTaskContainer = document.createElement("li");
        const newTask = document.createElement("input");
        const newTaskLabel = document.createElement("span");
        newTask.setAttribute("type", "checkbox");
        newTaskLabel.textContent = task;
        newTaskContainer.appendChild(newTask, newTaskLabel);
        todoList.appendChild(newTaskContainer);
        todoInput.value = "";
    }
}
