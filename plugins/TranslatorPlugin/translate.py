from googletrans import Translator #clasa ce ajuta la traducere

import sys # pentru extragerea argumentelor din comanda
translator = Translator() #cream o instanta a clase Translator

sentence = sys.argv[1] #Propozitia ce trebuie tradusa
_from = sys.argv[2]    #limba din care se traduce
_to = sys.argv[3]      #limba in care trebuie sa se faca traducerea

#functia de traducere propriu-zisa:
translation = translator.translate(sentence, src = _from, dest = _to)
print(translation.text) #afisarea textului tradus