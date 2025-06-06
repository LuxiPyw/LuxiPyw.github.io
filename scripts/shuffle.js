document.addEventListener('DOMContentLoaded', function() {
    const container = document.getElementById('container');
    if (!container) return;

    const paragraphs = container.getElementsByTagName('p');
    const sentences = Array.from(paragraphs); 
    for (let i = sentences.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        container.appendChild(sentences[j]);
    }
});
