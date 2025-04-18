function generate_stars(){
    const container = document.querySelector('body');
    for(let i = 0;i < 1000; ++i){
        const star = document.createElement('div');
        star.className = 'star';
        star.style.width = "1px";
        star.style.height = "1px";
        star.style.top = Math.floor(Math.random()*100) + "%";
        star.style.left = Math.floor(Math.random()*100) + "%";
        container.appendChild(star);
}
}
generate_stars()