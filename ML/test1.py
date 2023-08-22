import numpy as np
import matplotlib.pyplot as plt
import librosa
import librosa.display

data,sampling_rate=librosa.load('rock.00000.wav')
#plt.figure(figsize=(12,4))
#librosa.display.waveplot(data,sr=sampling_rate)

S=librosa.feature.melspectrogram(y=data,sr=22050,hop_length=512,n_fft=2048,n_mels=96)
plt.figure(figsize=(10,4))
S_dB=librosa.power_to_db(S**2)
librosa.display.specshow(S_dB,x_axis='time',y_axis='mel',sr=22050,fmax=8000)
plt.colorbar(format='%+2.0f dB')
plt.title('rock2')
plt.tight_layout()
plt.show()