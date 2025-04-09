# 🌌 fract-ol

**fract-ol** est un projet graphique de l'école 42 dont le but est de générer des fractales en utilisant la MiniLibX. C’est une belle introduction aux ensembles mathématiques complexes comme Mandelbrot et Julia, tout en manipulant des outils de rendu 2D.

## 🎯 Objectif

Créer un programme capable d’afficher plusieurs types de fractales et de permettre à l’utilisateur d’interagir avec elles (zoom, déplacement, changement de palette, etc.).

## 🧩 Fractales supportées

- 🌀 **Mandelbrot**
- 🌱 **Julia**
- 🌸 **Burning Ship** 

Chaque fractale est dessinée point par point via des calculs complexes sur les nombres imaginaires.

## 🧱 Fonctionnalités

- 📈 Zoom avant / arrière avec la molette
- 🎮 Déplacement avec les flèches directionnelles
- 🎨 Changement de palette de couleurs (avec la touche `C`)
- ⚓ Réinitialiser la vue (avec la touche `I`)
- 🔍 Augmenter ou diminuer l'itéraction max par pixel (avec les touches `+` et `-`)
- ❌ Fermeture propre avec `ESC` ou la croix de fenêtre

## ▶️ Lancement

mandelbrot : 
```bash
make
./fractol m
```

julia : 
```bash
make
./fractol j -0.8 0.156
```

burning_ship :
```bash
make
./fractol b
```

