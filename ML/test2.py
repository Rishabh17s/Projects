import librosa
import librosa.display
import numpy as np
import matplotlib.pyplot as plt
import os

plt.figure(figsize=(10,10))
genres = 'classical hiphop jazz pop rock'.split()
for g in genres:
    for filename in os.listdir(f'./genres/{g}'):
        data,sampling_rate=librosa.load(f'./genres/{g}/{filename}')
        S=librosa.feature.melspectrogram(y=data,sr=22050,hop_length=256,n_fft=512,n_mels=64)
        S_dB=librosa.power_to_db(S**2)
        librosa.display.specshow(S_dB,x_axis='time',y_axis='mel',sr=22050,fmax=8000)
        plt.colorbar(format='%+2.0f dB')
        plt.title('spectrogram')
        plt.tight_layout()
        plt.savefig(f'./genres2/{g}/{filename[:-3].replace(".", "")}.png')
        plt.clf()