# battery_notifier

## Prérequis
> apt install acpi

## Installation
> cd battery_notifier
> gcc battery_notifier.c -o battery_notifier_comp
> nano battery_notifier.sh

Rentrer les lignes suivantes:
> screen -dmS battery_notifier /chemin/absolu/vers/le/fichier/battery_notifier_comp

Ensuite on exécute automatiquement le script au démarrage:
> crontab -e

Choisir son éditeur puis ajouter à la fin du fichier la ligne suivante:
>@reboot /chemin/absolu/vers/le/fichier/battery_level_notif.sh

Voila fini !
