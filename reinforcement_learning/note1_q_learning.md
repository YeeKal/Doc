## Q learning algorithm:

1. initialize $Q$-values($Q(s,a)$) arbitrarity for all state-action pairs.
2. For the life or unitil learning is stopped...
    - Choose an action $(a)$ in the current world state $(s)$ based on current Q-value estimates $(Q(s,:))$.
    - Take the action $(a)$ and observe the outcome state $(s')$ and reward $(r)$.
    - Update $Q(s,a):=Q(s,a)+\alpha[r+\gamma \max_{a'}Q(s',a')-Q(s,a)]$

- epsilon: exploration rate
- gamma: 
- alpha: learning rate

## 策略选择

以一定的比率(epsilon)进行随机选择，这个比率值随着迭代轮次的减少而衰减。随机选择是探索的过程。而在贪婪阶段则进行最大选择。
> epsilon = min_epsilon + (max_epsilon - min_epsilon)*np.exp(-decay_rate*episode)

## 奖励定义

达到目的-避开障碍-移动一步

奖励的定义比较复杂。

## gym api

```
env = gym.make("FrozenLake-v0") #create the environment
print(gym.envs.registry.all())  #all registry envs

#space
env.action_space    #action space
env.observation_space  #state space
    #discrete space Discrete(n)
    #continuous space Box(n,)
    s=space.sample()  #random sample
    assert space.contains(s)    #check something belongs space

env.reset()         #Reset the environment's state. Returns observation.
env.step(action)    #Step the environment by one timestep. Returns observation, reward, done, info
env.render()        #Render one frame of the environment

```



