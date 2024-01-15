import pandas as pd
from sklearn.preprocessing import LabelEncoder
from joblib import load
from sklearn.metrics import confusion_matrix, accuracy_score, classification_report
from sklearn.ensemble import RandomForestClassifier

# Charger le modèle Random Forest
rf_model = load('./random_forest_model.joblib')

# Charger le dataset à partir d'un fichier CSV
df = pd.read_csv('./clean_dataset.csv')

# Convertir les caractéristiques catégorielles en valeurs numériques
label_encoder = LabelEncoder()
df['type'] = label_encoder.fit_transform(df['type'])

# Prédictions sur l'ensemble de données
predictions = rf_model.predict(df.drop('isFraud', axis=1))

# Convertir les prédictions en 'Y' (fraude) et 'N' (non fraude)
df['FraudeYN'] = ['Y' if x == 1 else 'N' for x in predictions]

# Enregistrer le dataframe avec la nouvelle colonne
df.to_csv('clean_with_fraud_random_forest.csv', index=False)

# Compter le nombre de fraudes
nombre_fraudes = df['FraudeYN'].value_counts()['Y']

print(f'Nombre de fraudes détectées : {nombre_fraudes}')

# Calculer la matrice de confusion
conf_matrix = confusion_matrix(df['isFraud'], predictions)

# Obtenir les valeurs de la matrice de confusion
tn, fp, fn, tp = conf_matrix.ravel()

# Calculer la précision
precision = (tp + tn) / (tp + tn + fp + fn) * 100

# Afficher les résultats
print("Faux positifs :", fp)
print("Faux négatifs :", fn)
print("Vrais positifs :", tp)
print("Vrais négatifs :", tn)
print("Précision de la prédiction en % :", precision)

# Afficher le rapport de classification
print("Rapport de classification :\n",
      classification_report(df['isFraud'], predictions))
