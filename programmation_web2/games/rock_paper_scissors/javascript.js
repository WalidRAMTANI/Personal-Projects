const UserChoice = document.getElementById('user-choice');
const ComputerChoice = document.getElementById('computer-choice');
const DifferentPossibilities = document.querySelectorAll('button');
console.log(DifferentPossibilities[0]);
const Result = document.getElementById('result');
DifferentPossibilities.forEach(possibility => possibility.addEventListener('click', (event) =>
{
    UserChoice.innerHTML = event.target.id;
    GenerateComputerChoice();
    Winner(ComputerChoice, UserChoice);
}));
function GenerateComputerChoice(){
    const choice = Math.floor(Math.random()*3);
    if (choice === 0)
        ComputerChoice.innerHTML = 'Scissor';
    else if (choice === 1)
        ComputerChoice.innerHTML = 'Paper';
    else
        ComputerChoice.innerHTML = 'Rock';
    return ComputerChoice.textContent;
}
function Winner(ComputerChoice, UserChoice){
    if (UserChoice.innerHTML == ComputerChoice.innerHTML)
        Result.innerHTML = 'Its a draw !! ';
    else if(UserChoice.innerHTML == 'Rock' && ComputerChoice.innerHTML == 'Paper' || 
            UserChoice.innerHTML == 'Paper' && ComputerChoice.innerHTML == 'Scissor' || 
            UserChoice.innerHTML == 'Scissor' && ComputerChoice.innerHTML == 'Rock')
       Result.innerHTML = "You lose!!";
    else
        Result.innerHTML = 'You win !!';
}
