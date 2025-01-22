let padding_left = 0;
function deplacer_left(){
    const element = document.getElementById('grid-actualites');
    padding_left -= 50;
    element.style.paddingLeft = padding_left + 'px';
};
function deplacer_right(){
    const element = document.getElementById('grid-actualites');
    padding_left += 50;
    element.style.paddingLeft = padding_left + 'px';
};