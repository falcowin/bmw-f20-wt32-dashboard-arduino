# Comandi OBD2 - BMW F20

## 📖 Introduzione

Questo documento elenca i PID (Parameter IDs) OBD2 supportati per la BMW F20, come leggerli e interpretarli.

## 🔍 Comandi Supportati

### Motore - Giri e Velocità

| PID | Comando | Descrizione | Unità | Formula |
|-----|---------|-------------|-------|----------|
| 0x0C | `01 0C` | RPM motore | RPM | ((A×256)+B)/4 |
| 0x0D | `01 0D` | Velocità veicolo | km/h | A |

### Motore - Temperature

| PID | Comando | Descrizione | Unità | Formula |
|-----|---------|-------------|-------|----------|
| 0x05 | `01 05` | Temp. liquido raffreddamento | °C | A-40 |

### Carburante

| PID | Comando | Descrizione | Unità | Formula |
|-----|---------|-------------|-------|----------|
| 0x2F | `01 2F` | Livello carburante | % | (A/255)×100 |

### Batteria

| PID | Comando | Descrizione | Unità | Formula |
|-----|---------|-------------|-------|----------|
| 0x42 | `01 42` | Voltaggio batteria | V | ((A×256)+B)/1000 |

## 🚨 Codici Diagnostici (DTC)

### Lettura DTC
```
Comando: 19 02
Risposta: 59 02 [DTC Data]
```

### Cancellazione DTC
```
Comando: 04
```

## 📝 Esempi di Utilizzo

### Lettura RPM
```
Invio:  01 0C
Risposta: 41 0C 10 2A
Calcolo: RPM = ((0x10 × 256) + 0x2A) / 4 = 1034.5 RPM
```

### Lettura Velocità
```
Invio:  01 0D
Risposta: 41 0D 46
Calcolo: Velocità = 0x46 = 70 km/h
```

### Lettura Temperatura Motore
```
Invio:  01 05
Risposta: 41 05 6E
Calcolo: Temp = 0x6E - 40 = 110 - 40 = 70°C
```

## 📊 Intervalli Normali BMW F20

| Parametro | Min | Normale | Max | Unità |
|-----------|-----|---------|-----|-------|
| RPM Idle | 600 | 800 | 1200 | RPM |
| Velocità | 0 | - | 240 | km/h |
| Temp. Motore | 80 | 90 | 110 | °C |
| Livello Carburante | 0 | - | 100 | % |
| Voltaggio Batteria | 11.5 | 14 | 14.5 | V |

---

**Ultimo aggiornamento**: 2026-06-04