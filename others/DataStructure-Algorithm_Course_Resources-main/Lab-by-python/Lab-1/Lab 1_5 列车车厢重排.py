def place_car(car, tracks):
    """Place a car into the appropriate track."""
    for track in tracks:
        if track[-1] > car:
            track.append(car)
            return
    tracks.append([car])


def print_result(car, tracks):
    """Print the track containing the specified car and the total number of tracks."""
    for track in tracks:
        if car in track:
            print(" ".join(str(x) for x in track))
            break
    print(len(tracks))


def main():
    n = int(input().strip())
    cars = list(map(int, input().strip().split()))

    tracks = []
    for car in cars:
        place_car(car, tracks)

    print_result(1, tracks)


if __name__ == "__main__":
    main()
