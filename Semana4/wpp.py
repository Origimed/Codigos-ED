import requests

# URL del endpoint de la API de WhatsApp
url = "https://graph.facebook.com/v21.0/504289809439094/messages"

# Encabezados
headers = {
    "Authorization": "Bearer EAASQZCMAY46kBOylQjgvZC5ZCuKGts9elEZCk6T465OnsIrH6CyOHgHtiP2dMrXywgFHg1oVIGJt175weXxJ6iHrjXveJTshjtBP2TGG98NrKhoMWJyxwrlGRZALBJxwMfTgpDHzoLx55E7UcIsjpClY8870gnxgV4zerMfUljD58y7X9nZCAa6m2Pufmy2NrWDktedcqjf3XLOkfkokdBY2keoTZCn",
    "Content-Type": "application/json"
}

# Cuerpo del mensaje
data = {
    "messaging_product": "whatsapp",
    "to": "3115118989",  # Número de teléfono del destinatario en formato internacional
    "type": "template",
    "template": {
        "name": "plantilla1",  # Nombre exacto de la plantilla aprobada
        "language": {
            "code": "es"  # Código del idioma en el que fue aprobada la plantilla
        },
        "components": [
            {
                "type": "body",
                "parameters": [
                    {"type": "text", "text": "Holaaaaaaaaaa Mariaaaaaaaaaaaaaaaaaaaaaaaaa"},  # Sustitución del primer {{texto}}
                    {"type": "text", "text": "2024-12-30"}            # Sustitución del segundo {{texto}}
                ]
            }
        ]
    }
}

# Enviar la solicitud POST
response = requests.post(url, headers=headers, json=data)

# Verificar la respuesta
print("Estado:", response.status_code)
print("Respuesta:", response.json())
