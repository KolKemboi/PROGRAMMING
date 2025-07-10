from time import sleep

joints_pos = {
    "leg_1" : {
        "joint_1" : 0.0,
        "joint_2" : 0.0,
        "joint_3" : 0.0,
        "joint_4" : 0.0,
    }, 
    "leg_2" : {
        "joint_1" : 0.0,
        "joint_2" : 0.0,
        "joint_3" : 0.0,
        "joint_4" : 0.0,
    },
    "leg_3" : {
        "joint_1" : 0.0,
        "joint_2" : 0.0,
        "joint_3" : 0.0,
        "joint_4" : 0.0,
    },
    "leg_4" : {
        "joint_1" : 0.0,
        "joint_2" : 0.0,
        "joint_3" : 0.0,
        "joint_4" : 0.0,
    }
}

joints_max_lims = {
    "leg_1" : {
        "joint_1" : 0.174,
        "joint_2" : 1.04,
        "joint_3" : 2.04,
        "joint_4" : 3.14,
    }, 
    "leg_2" : {
        "joint_1" : 0.174,
        "joint_2" : 1.04,
        "joint_3" : 2.04,
        "joint_4" : 3.14,
    },
    "leg_3" : {
        "joint_1" : 0.174,
        "joint_2" : 1.04,
        "joint_3" : 2.04,
        "joint_4" : 3.14,
    },
    "leg_4" : {
        "joint_1" : 0.174,
        "joint_2" : 1.04,
        "joint_3" : 2.04,
        "joint_4" : 3.14,
    }
}

joints_min_lims = {
    "leg_1" : {
        "joint_1" : -0.174,
        "joint_2" : -1.04,
        "joint_3" : -2.04,
        "joint_4" : -3.14,
    }, 
    "leg_2" : {
        "joint_1" : -0.174,
        "joint_2" : -1.04,
        "joint_3" : -2.04,
        "joint_4" : -3.14,
    },
    "leg_3" : {
        "joint_1" : -0.174,
        "joint_2" : -1.04,
        "joint_3" : -2.04,
        "joint_4" : -3.14,
    },
    "leg_4" : {
        "joint_1" : -0.174,
        "joint_2" : -1.04,
        "joint_3" : -2.04,
        "joint_4" : -3.14,
    }
}

def log():
    print(joints_pos.get("leg_1"))
    print("-" * 100)
    print(joints_pos.get("leg_2"))
    print("-" * 100)
    print(joints_pos.get("leg_3"))
    print("-" * 100)
    print(joints_pos.get("leg_4"))
    print("-" * 100)

def leg_mvt(appandage):
    leg_sets = {
        "leg_1" : {
            "move": "leg_1",
            "rotate": "leg_2"
        },
        "leg_2" : {
            "move": "leg_2",
            "rotate": "leg_1"
        },
        "leg_3" : {
            "move": "leg_3",
            "rotate": "leg_4"
        },
        "leg_4" : {
            "move": "leg_4",
            "rotate": "leg_3"
        },
    }
    if appandage == "leg_1":
        raise_leg = leg_sets.get("leg_1").get("move")
        rotate_leg = leg_sets.get("leg_1").get("rotate")
    elif appandage == "leg_2":
        raise_leg = leg_sets.get("leg_2").get("move")
        rotate_leg = leg_sets.get("leg_2").get("rotate")
    elif appandage == "leg_3":
        raise_leg = leg_sets.get("leg_3").get("move")
        rotate_leg = leg_sets.get("leg_3").get("rotate")
    elif appandage == "leg_4":
        raise_leg = leg_sets.get("leg_4").get("move")
        rotate_leg = leg_sets.get("leg_4").get("rotate")
    #MOVE
    #raise last
    raise_pos = joints_pos.get(raise_leg).get("joint_4")
    raise_min = joints_min_lims.get(raise_leg).get("joint_4")
    if raise_min < raise_pos:
        joints_pos[raise_leg]["joint_4"] = raise_min 

    sleep(4)

    print("current")
    log()
    

    sleep(4)
    #rotate first
    move_pos = joints_pos.get(raise_leg).get("joint_1")
    move_max = joints_max_lims.get(raise_leg).get("joint_1")
    if move_max > move_pos:
        joints_pos[raise_leg]["joint_1"] = move_max

    #ROTATE
    #rotate first
    rotate_pos = joints_pos.get(rotate_leg).get("joint_1")
    rotate_min = joints_min_lims.get(rotate_leg).get("joint_1")
    if rotate_min < rotate_pos:
        joints_pos[rotate_leg]["joint_1"] = rotate_min 
    
    print("Moving")
    log()

    sleep(4)
    print("Lowering Joint")
    #lower raised leg
    joints_pos[raise_leg]["joint_4"] = 0.0
    log()

def move_bot():
    joints_pos = {
        "leg_1" : {
            "joint_1" : 0.0,
            "joint_2" : 0.0,
            "joint_3" : 0.0,
            "joint_4" : 0.0,
        }, 
        "leg_2" : {
            "joint_1" : 0.0,
            "joint_2" : 0.0,
            "joint_3" : 0.0,
            "joint_4" : 0.0,
        },
        "leg_3" : {
            "joint_1" : 0.0,
            "joint_2" : 0.0,
            "joint_3" : 0.0,
            "joint_4" : 0.0,
        },
        "leg_4" : {
            "joint_1" : 0.0,
            "joint_2" : 0.0,
            "joint_3" : 0.0,
            "joint_4" : 0.0,
        }
    }
    leg_mvt("leg_1")
    print("LEG_1_MOVED")
    leg_mvt("leg_3")
    print("LEG_3_MOVED")
    leg_mvt("leg_2")
    print("LEG_2_MOVED")
    leg_mvt("leg_4")
    print("LEG_4_MOVED")

    print("-"*100)
    print("-"*100)
    print("-"*100)

    leg_mvt("leg_1")
    print("LEG_1_MOVED")
    leg_mvt("leg_3")
    print("LEG_3_MOVED")
    leg_mvt("leg_2")
    print("LEG_2_MOVED")
    leg_mvt("leg_4")
    print("LEG_4_MOVED")

move_bot()