import pandas as pd
df = pd.read_csv("heart.csv")

# %%

print(df.head(3))
print(df.tail(3))

# %%

print(df.shape)
print(df.rank())

# %% 
print(df.columns)
print(df.index)

# %%

cols = df.columns
for col in cols:
    print(col)

# %%

for col in cols:
    print(df[col])

# %% 
df.count()


# %% 
df.sum()

# %% 
df.cumsum()


# %% 
# df.min()/df.max()
# %% 

df.describe()
# %% 
for col in cols:
    print( df[col].describe())
# %%
